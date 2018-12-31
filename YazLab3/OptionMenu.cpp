#include "OptionMenu.h"

OptionMenu::OptionMenu(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.comboBox->addItems(QStringList() << "4:4:4" << "4:2:2" << "4:2:0");
}

OptionMenu::~OptionMenu()
{
}

int* OptionMenu::getSettings()
{
	int settings[] = { ui.lineEdit->text().toInt(), ui.lineEdit_2->text().toInt(), ui.comboBox->currentIndex() };
	return settings;
}

void OptionMenu::setSettings(int img_width, int img_height, int img_format)
{
	ui.lineEdit->setText(QString::number(img_width));
	ui.lineEdit_2->setText(QString::number(img_height));
	ui.comboBox->setCurrentIndex(img_format);
}

void OptionMenu::on_pushButton_clicked()
{
	
}