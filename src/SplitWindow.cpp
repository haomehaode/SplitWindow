#include "SplitWindow.h"
#include <QSplitter>
#include <QHBoxLayout>
#include <QLabel>

SplitWindow::SplitWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	QWidget* newWidget = new QWidget();
	newWidget->setFocusPolicy(Qt::ClickFocus);
	QPalette pal(newWidget->palette());
	pal.setColor(QPalette::Background, Qt::red);
	newWidget->setAutoFillBackground(true);
	newWidget->setPalette(pal);

	QHBoxLayout* layout = new QHBoxLayout;
	layout->setMargin(0);
	layout->setSpacing(0);
	layout->addWidget(newWidget);
	QWidget* main_widget = new QWidget(this);
	main_widget->setObjectName("mian_widget");
	main_widget->setLayout(layout);
    setCentralWidget(main_widget);

}

void SplitWindow::slot_vertical_splitter()
{
	//要分割的Widget
	QWidget* splitter_widget = focusWidget();
	if (splitter_widget == nullptr)
		return;
	//要分割的Widget的parentWidget为QSplitter
	if (dynamic_cast<QSplitter*>(splitter_widget->parentWidget()) != nullptr)
	{
		QSplitter* parent_splitter = qobject_cast<QSplitter*>(splitter_widget->parentWidget());
		QSplitter* splitter= new QSplitter(Qt::Vertical);
		QWidget* old_widget= parent_splitter->replaceWidget(parent_splitter->indexOf(splitter_widget), splitter);
		splitter->addWidget(old_widget);
		QWidget* new_widget = new QWidget();
		new_widget->setFocusPolicy(Qt::ClickFocus);
		QPalette pal(new_widget->palette());
		pal.setColor(QPalette::Background, Qt::blue);
		new_widget->setAutoFillBackground(true);
		new_widget->setPalette(pal);
		splitter->addWidget(new_widget);
	}
	//要分割的Widget的parentWidget为QWidget
	else
	{
		QSplitter* splitter = new QSplitter(Qt::Vertical);
		splitter_widget->parentWidget()->layout()->replaceWidget(splitter_widget, splitter);
		splitter->addWidget(splitter_widget);
		QWidget* new_widget = new QWidget();
		new_widget->setFocusPolicy(Qt::ClickFocus);
		QPalette pal(new_widget->palette());
		pal.setColor(QPalette::Background, Qt::black);
		new_widget->setAutoFillBackground(true);
		new_widget->setPalette(pal);
		splitter->addWidget(new_widget);
	}
}

void SplitWindow::slot_horizontal_splitter()
{
	//要分割的Widget
	QWidget* splitter_widget = focusWidget();
	if (splitter_widget == nullptr)
		return;
	//要分割的Widget的parentWidget为QSplitter
	if (dynamic_cast<QSplitter*>(splitter_widget->parentWidget()) != nullptr)
	{
		QSplitter* parent_splitter = qobject_cast<QSplitter*>(splitter_widget->parentWidget());
		QSplitter* splitter = new QSplitter(Qt::Horizontal);
		QWidget* old_widget = parent_splitter->replaceWidget(parent_splitter->indexOf(splitter_widget), splitter);
		splitter->addWidget(old_widget);
		QWidget* new_widget = new QWidget();
		new_widget->setFocusPolicy(Qt::ClickFocus);
		QPalette pal(new_widget->palette());
		pal.setColor(QPalette::Background, Qt::blue);
		new_widget->setAutoFillBackground(true);
		new_widget->setPalette(pal);
		splitter->addWidget(new_widget);
	}
	//要分割的Widget的parentWidget为QWidget
	else
	{
		QSplitter* splitter = new QSplitter(Qt::Horizontal);
		splitter_widget->parentWidget()->layout()->replaceWidget(splitter_widget, splitter);
		splitter->addWidget(splitter_widget);
		QWidget* new_widget = new QWidget();
		new_widget->setFocusPolicy(Qt::ClickFocus);
		QPalette pal(new_widget->palette());
		pal.setColor(QPalette::Background, Qt::black);
		new_widget->setAutoFillBackground(true);
		new_widget->setPalette(pal);
		splitter->addWidget(new_widget);
	}
}

void SplitWindow::slot_delete_splitter()
{
	QWidget* splitter_widget = focusWidget();
	if (splitter_widget == nullptr)
		return;
	if (dynamic_cast<QSplitter*>(splitter_widget->parentWidget()) == nullptr)
		return;
	QSplitter* parent_splitter = qobject_cast<QSplitter*>(splitter_widget->parentWidget()->parentWidget());
	if (parent_splitter != nullptr) 
	{
		QSplitter* splitter = qobject_cast<QSplitter*>(splitter_widget->parentWidget());
		QWidget* old_widget = splitter->replaceWidget(!splitter->indexOf(splitter_widget), new QWidget());
		parent_splitter->replaceWidget(parent_splitter->indexOf(splitter), old_widget);
		delete splitter;
	}
	else
	{
		QSplitter* splitter = qobject_cast<QSplitter*>(splitter_widget->parentWidget());
		QWidget* old_widget = splitter->replaceWidget(!splitter->indexOf(splitter_widget),new QWidget());
		splitter_widget->parentWidget()->parentWidget()->layout()->replaceWidget(splitter_widget->parentWidget(), old_widget);
		delete splitter;
	}
}

void SplitWindow::slot_add_label()
{
	QWidget* widget = focusWidget();

	if (widget == nullptr)
		return;

	if (widget->layout() == nullptr)
	{
		QHBoxLayout* layout = new QHBoxLayout;
		layout->setMargin(0);
		layout->setSpacing(0);
		layout->addWidget(new QLabel("Test"));
		widget->setLayout(layout);
	}
	else
		widget->layout()->addWidget(new QLabel("Test"));
}
