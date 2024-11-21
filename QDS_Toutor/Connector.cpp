#include "Connector.h"

Connector::Connector(QObject *parent)
	: QObject(parent)
{
	this->timer.start(1000);
	connect(&this->timer, &QTimer::timeout, this, &Connector::onTimer);
}

Connector::~Connector()
{}

Q_INVOKABLE void Connector::setValue(const QString & string)
{
	this->string = string;
	return Q_INVOKABLE void();
}

Q_INVOKABLE QString Connector::getValue()
{
	return Q_INVOKABLE this->string;
}

void Connector::onTimer()
{
	QString str_output = QString::number(index++);
	emit this->sig_updateValue(str_output);
}
