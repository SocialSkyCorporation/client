/*
 * Copyright (C) by Klaas Freitag <freitag@owncloud.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#ifndef SYNCRUNFILELOG_H
#define SYNCRUNFILELOG_H

#include <QFile>
#include <QTextStream>
#include <QScopedPointer>
#include <QElapsedTimer>

#include "syncfileitem.h"

namespace OCC {
class SyncFileItem;

/**
 * @brief The SyncRunFileLog class
 * @ingroup gui
 */
class SyncRunFileLog
{
public:
    SyncRunFileLog();
    void start( const QString& folderPath );
    void logItem( const SyncFileItem& item );
    void finish();

protected:

private:
    QString dateTimeStr( const QDateTime& dt );
    QString instructionToStr( csync_instructions_e inst );
    QString directionToStr( SyncFileItem::Direction dir );

    QScopedPointer<QFile> _file;
    QTextStream _out;
    QElapsedTimer _duration;
};
}

#endif // SYNCRUNFILELOG_H
