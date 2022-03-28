#include <QtWidgets/QApplication>
#include "SplitWindow.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	SplitWindow w;
	w.show();

	return a.exec();
}