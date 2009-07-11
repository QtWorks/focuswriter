/***********************************************************************
 *
 * Copyright (C) 2008-2009 Graeme Gott <graeme@gottcode.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <QHash>
#include <QMainWindow>
class QAction;
class QLabel;
class QTabBar;
class QToolBar;
class Preferences;
class Stack;

class Window : public QMainWindow {
	Q_OBJECT
public:
	Window();

protected:
	virtual bool event(QEvent* event);
	virtual void closeEvent(QCloseEvent* event);
	virtual void resizeEvent(QResizeEvent* event);

private slots:
	void newDocument();
	void openDocument();
	void renameDocument();
	void saveAllDocuments();
	void closeDocument();
	void toggleFullscreen();
	void toggleToolbar(bool visible);
	void themeClicked();
	void preferencesClicked();
	void aboutClicked();
	void tabClicked(int index);
	void tabMoved(int from, int to);
	void tabClosed(int index);
	void updateClock();
	void updateDetails();
	void updateProgress();
	void updateSave();

private:
	void addDocument(const QString& filename = QString());
	bool saveDocument(int index);
	void loadPreferences(const Preferences& preferences);
	void updateMargin();
	void updateTab(int index);
	void initMenuBar();
	void initToolBar();

private:
	QWidget* m_header;
	QMenuBar* m_menubar;
	QToolBar* m_toolbar;
	QHash<QString, QAction*> m_actions;

	Stack* m_documents;
	QTabBar* m_tabs;
	int m_margin;

	QWidget* m_footer;
	QLabel* m_character_label;
	QLabel* m_page_label;
	QLabel* m_paragraph_label;
	QLabel* m_wordcount_label;
	QLabel* m_progress_label;
	QLabel* m_clock_label;
	QTimer* m_clock_timer;

	bool m_fullscreen;
	bool m_auto_save;
	int m_goal_type;
	int m_time_goal;
	int m_wordcount_goal;
	int m_current_time;
	int m_current_wordcount;
};

#endif
