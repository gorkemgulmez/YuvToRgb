#pragma once

#include <QDialog>
#include "ui_OptionMenu.h"
#include <QString>

class OptionMenu : public QDialog
{
	Q_OBJECT

public:
	OptionMenu(QWidget *parent = Q_NULLPTR);
	~OptionMenu();
	int* getSettings();
	void setSettings(int img_width, int img_height, int img_format);

private:
	Ui::OptionMenu ui;

private slots:
	void on_pushButton_clicked();
};
