#pragma once

#include "disk.h"
#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMenu>
#include <QLineEdit>
#include <QMenuBar>

class Widget:public QWidget
{
	Q_OBJECT
public:
	Widget();
protected slots:
	void onClickedOpenAction();
	void searchUpdate();
private:
	QVector<Disk> disks;
	QListWidget* widget;
	QLineEdit* searchEdit;


};

