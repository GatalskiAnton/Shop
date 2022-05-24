#include "widget.h"

Widget::Widget()
{
	QMenu* file = new QMenu("File",this);
	QAction* openAction = new QAction("Open");
	file->addAction(openAction);
	QMenuBar* menuBar = new QMenuBar(this);
	menuBar->addMenu(file);

	widget = new QListWidget(this);

	searchEdit = new QLineEdit(this);

	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	mainLayout->addWidget(menuBar);
	mainLayout->addWidget(searchEdit);
	mainLayout->addWidget(widget);

	connect(openAction, SIGNAL(triggered()), SLOT(onClickedOpenAction()));
	connect(searchEdit, SIGNAL(textChanged(const QString&)), SLOT(searchUpdate()));
}

void Widget::onClickedOpenAction()
{
	QString qStr = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
	readFromFile(disks, qStr.toStdString());

	for (auto& disk : disks)
		widget->addItem(disk.getType() + " " + disk.getAuthor() + " " + disk.getTitle());
}

void Widget::searchUpdate()
{
	if (searchEdit->text().isEmpty())
	{
		widget->clear();
		for (auto& disk : disks)
			widget->addItem(disk.getType() + " " + disk.getAuthor() + " " + disk.getTitle());
		
	}

	for (auto& disk : disks)
	{
		if (disk.getAuthor().contains(searchEdit->text()) || disk.getTitle().contains(searchEdit->text()))
		{
			widget->clear();
			widget->addItem(disk.getType() + " " + disk.getAuthor() + " " + disk.getTitle());
		}
	}
}
