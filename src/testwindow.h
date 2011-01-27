/**************************************************************************
 *  Karlyriceditor - a lyrics editor for Karaoke songs                    *
 *  Copyright (C) 2009 George Yunaev, support@karlyriceditor.com          *
 *                                                                        *
 *  This program is free software: you can redistribute it and/or modify  *
 *  it under the terms of the GNU General Public License as published by  *
 *  the Free Software Foundation, either version 3 of the License, or     *
 *  (at your option) any later version.                                   *
 *																	      *
 *  This program is distributed in the hope that it will be useful,       *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *  GNU General Public License for more details.                          *
 *                                                                        *
 *  You should have received a copy of the GNU General Public License     *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 **************************************************************************/

#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QDialog>
#include <QString>

#include "ui_testwindow.h"
#include "lyrics.h"
#include "cdgrenderer.h"
#include "lyricsrenderer.h"


class TestWindow : public QDialog, public Ui::TestWindow
{
    Q_OBJECT

	public:
		TestWindow(QWidget *parent = 0);

		// For lyrics
		void	setLyrics( const Lyrics& lyrics, const QString& artist, const QString& title );

		// For CD+G
		void	setCDGdata( const QByteArray& cdgdata );

	public slots:
		void	tick( qint64 tickmark );

	protected:
		// overriden
		void	showEvent ( QShowEvent * event );
		void	hideEvent( QShowEvent * event );

	private:
		void	clear();
		void	reset();

	private:
		LyricsRenderer	* m_renderer;
};


#endif // TESTWINDOW_H
