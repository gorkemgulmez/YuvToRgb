#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_YazLab3.h"
#include <QPixmap>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>
#include <fstream>
#include <vector>
#include <QImage>
#include <QString>

using namespace std;

class YazLab3 : public QMainWindow
{
	Q_OBJECT

public:
	YazLab3(QWidget *parent = Q_NULLPTR);

private:
	Ui::YazLab3Class ui;
	int img_width = 0, img_height = 0, img_format = 0;
	int frameNumber, frameIterator;
	void setImageFormat(int x, int y, int format);
	void convertYuv(QString filename);
	vector<vector<unsigned char>> yuvData;
	vector<QImage> mapVector;

private:
	QTimer *timer = new QTimer(this);

private slots:
	void on_pushButton_clicked();	//Dosya
	//void on_pushButton_2_clicked();	//Ayarlar
	//void on_pushButton_3_clicked();	//Donustur
	void on_pushButton_4_clicked();	//Kaydet
	void on_pushButton_5_clicked();	//Oynat
	void play();					//QTimer Slot
};
