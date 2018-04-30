/*
 * Copyright 2018 (C) Ultimaker B.V.
 * Copyright 2018 (C) Olliver Schinagl <oliver@schinagl.nl>
 *
 * SPDX-License-Identifier: AGPL-3.0+
 *
 */

#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QTimer>

int main(int argc, char *argv[])
{

	QGuiApplication qtsplash(argc, argv);
	QQmlApplicationEngine engine;
	engine.load("/usr/share/qtsplash/resources/qtsplash.qml");

	QTimer *timer = new QTimer(&qtsplash);
	QObject::connect(timer, SIGNAL(timeout()), &qtsplash, SLOT(quit()));
	timer->start(1);

	return qtsplash.exec();
}
