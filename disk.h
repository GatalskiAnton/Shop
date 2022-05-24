#pragma once
#include <QString>
#include <istream>
#include <fstream>
#include <QVector>
#include <vector>
#include <QMessageBox>

class Disk
{
public:
	Disk() = default;
	Disk(QString type, QString title,QString author, float price, QString note):type_(type),title_(title),author_(author), price_(price),note_(note){};
	~Disk() = default;
public:
	QString getType();
	QString getTitle();
	QString getAuthor();
	float getPrice();
	QString getNote();
private:
	QString type_;
	QString title_;
	QString author_;
	float price_;
	QString note_;
};

std::istream& operator>>(std::istream&, Disk&);
void readFromFile(QVector<Disk>&, const std::string& fileName);
