#include "disk.h"



std::istream& operator>>(std::istream& input, Disk& disk)
{
	std::string type,title, author,note;
	float price;
	input >> type >> title >> author >> price >> note ;
	disk = Disk(QString::fromStdString(type), QString::fromStdString(title), QString::fromStdString(author),price, QString::fromStdString(note));
	return input;
}

void readFromFile(QVector<Disk>& disks, const std::string& fileName)
{
	std::ifstream input(fileName);
	Disk disk;

	while (input >> disk)
		disks.push_back(disk);
}


QString Disk::getType()
{
	return type_;
}

QString Disk::getTitle()
{
	return title_;
}

QString Disk::getAuthor()
{
	return author_;
}

float Disk::getPrice()
{
	return price_;
}

QString Disk::getNote()
{
	return note_;
}
