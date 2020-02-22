#pragma once

#include "main.hpp"
#include "spotify/spotify.hpp"
#include "spotify/playlist.hpp"
#include "spotify/playback.hpp"
#include "spotify/webplayer.hpp"
#include "spotify/audiofeatures.hpp"

#include <QMainWindow>
#include <QListWidget>
#include <QTreeWidget>
#include <QLabel>
#include <QSlider>
#include <QAction>
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QGroupBox>
#include <QIcon>
#include <QHeaderView>
#include <QStatusBar>
#include <QToolBar>
#include <QToolButton>
#include <QMenu>
#include <QMessageBox>
#include <QWebEngineView>
#include <QWebEngineSettings>
#include <QDockWidget>
#include <QTextEdit>
#include <QApplication>
#include <QMapIterator>

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow() override;
private:
	// Widgets
	QListWidget	*playlists;
	QTreeWidget	*songs;
	QLabel		*nowPlaying, *position, *nowAlbum;
	QSlider		*progress, *volume;
	QAction		*playPause, *repeat, *shuffle;
	// Everything else
	spt::Spotify			*spotify;
	QVector<spt::Playlist>	*sptPlaylists;
	spt::Playback			current;
	QNetworkAccessManager	*network;
	QDockWidget				*playerView;
	// Methods
	QWidget *createCentralWidget();
	QToolBar *createToolBar();
	QMenu *createMenu();
	void refreshPlaylists();
	bool loadPlaylist(spt::Playlist &playlist);
	void setStatus(const QString &message);
	void setCurrentSongIcon();
	void setAlbumImage(const QString &url);
	static QString formatTime(int ms);
	void refreshDevices(QMenu *deviceMenu);
	void refresh();
	QJsonDocument get(const QString &url);
	void openAudioFeaturesWidget(const QString &trackId, const QString &artist, const QString &name);
	void openLyrics(const QString &artist, const QString &name);
};
