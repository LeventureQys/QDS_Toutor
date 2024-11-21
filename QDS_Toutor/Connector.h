#pragma once

#include <QObject>
#include "qtimer.h"
class Connector  : public QObject
{
	Q_OBJECT

public:
	Connector(QObject *parent);
	~Connector();
	Q_INVOKABLE void setValue(const QString& string);
	Q_INVOKABLE QString getValue();
signals:
	Q_INVOKABLE void sig_updateValue(const QString& strMessage);
private:
	QString string;
	QTimer timer;
	void onTimer();
	int index = 0;
};
