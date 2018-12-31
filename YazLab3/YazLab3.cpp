#include "YazLab3.h"
#include "OptionMenu.h"

#define FPS 25

YazLab3::YazLab3(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.progressBar->setVisible(false);
	connect(timer, SIGNAL(timeout()), this, SLOT(play()));
}

void YazLab3::on_pushButton_clicked()
{
	QString filename = QFileDialog::getOpenFileName(
		this,
		tr("Yuv Dosyasi"),
		QDir::currentPath(),
		"Yuv files (*.yuv)"
	);

	if (filename.isNull()) return;

	OptionMenu o(this);
	o.setModal(true);
	o.setSettings(img_width, img_height, img_format);

	if (o.exec() == QDialog::Rejected) {
		int* settings = o.getSettings();
		setImageFormat(settings[0], settings[1], settings[2]);
	}

	convertYuv(filename);
}

/*void YazLab3::on_pushButton_2_clicked()
{
	OptionMenu o(this);
	o.setModal(true);
	o.setSettings(img_width, img_height, img_format);

	if (o.exec() == QDialog::Rejected) {
		int* settings = o.getSettings();
		setImageFormat(settings[0], settings[1], settings[2]);
		return;
	}
}

void YazLab3::on_pushButton_3_clicked()
{
	convertYuv();
}*/

void YazLab3::on_pushButton_4_clicked()
{
	QString foldername = QFileDialog::getExistingDirectory(
		this,
		tr("Dosyayi Kaydet"),
		QDir::currentPath()
	);

	if (foldername.isNull()) return;

	ui.progressBar->setVisible(true);
	ui.progressBar->setValue(0);
	for (int i = 0; i < frameNumber; i++) {
		ui.progressBar->setValue(50);
		QString path = foldername + "/" + QString::number(i) + ".bmp";
		mapVector[i].save(path, "BMP");
	}
	ui.progressBar->setVisible(false);
}

void YazLab3::on_pushButton_5_clicked()
{
	if (timer->isActive()) {
		timer->stop();
		ui.pushButton_5->setText(QString("Oynat"));
	}
	else {
		timer->start(1000 / FPS);
		ui.pushButton_5->setText(QString("Durdur"));
	}
}

void YazLab3::setImageFormat(int x, int y, int format)
{
	img_width = x;
	img_height = y;
	img_format = format;
	
	ui.label->setGeometry(QRect(150, 130, img_width, img_height));
}

void YazLab3::play()
{
	QPixmap pm = QPixmap::fromImage(mapVector[frameIterator]);
	
	ui.label->setPixmap(pm);
	frameIterator++;
	if (frameIterator >= frameNumber) frameIterator = 0;
}

void YazLab3::convertYuv(QString filename)
{
	QByteArray qba = filename.toLatin1();
	const char *path = qba.data();
	int Y_byte = img_width*img_height;
	int UV_btye;
	if (img_format == 0) UV_btye = Y_byte * 2;
	else if(img_format == 1) UV_btye = Y_byte;
	else	/* img_format == 2*/ UV_btye = Y_byte * 1 / 2;

	ifstream ifs(path, ios::binary);
	ifs.seekg(0, ios_base::end);
	long size = ifs.tellg();
	ifs.seekg(0);

	const int frameNumber = size / (Y_byte + UV_btye);
	this->frameNumber = frameNumber;
	yuvData.resize(frameNumber);
	mapVector.resize(frameNumber);

	//Read YUV
	for (int i = 0; i < frameNumber; i++) {
		char* a = new char[UV_btye];
		yuvData[i].resize(Y_byte);
		ifs.read(reinterpret_cast<char*>(&yuvData[i][0]), Y_byte);
		ifs.read(a, UV_btye);
		delete a;
	}
	ifs.close();
	
	//Convert yuv -> rgb
	ui.progressBar->setVisible(true);
	ui.progressBar->setValue(0);
	for(int i=0; i<frameNumber; i++) {
		ui.progressBar->setValue(50);
		mapVector[i] = QPixmap(img_width, img_height).toImage();
		int x = 0, y = 0;
		for (auto pix : yuvData[i]) {
			int r, g, b;

			r = (pix + 1.4075);
			g = (pix - 0.3455);
			b = (pix + 1.7790);
			mapVector[i].setPixelColor(x, y, QColor(r, g, b));
			x++;
			if (x >= img_width) {
				x = 0;
				y++;
			}
		}
	}
	ui.progressBar->setVisible(false);
	timer->stop();
	ui.pushButton_5->setText("Oynat");
	frameIterator = 0;
}