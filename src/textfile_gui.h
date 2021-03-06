/* $Id: textfile_gui.h 25816 2013-10-06 11:29:14Z frosch $ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file textfile_gui.h GUI functions related to textfiles. */

#ifndef TEXTFILE_GUI_H
#define TEXTFILE_GUI_H

#include "fileio_type.h"
#include "strings_func.h"
#include "textfile_type.h"
#include "window_gui.h"

const char *GetTextfile(TextfileType type, Subdirectory dir, const char *filename);

/** Window for displaying a textfile */
struct TextfileWindow : public Window, MissingGlyphSearcher {
	TextfileType file_type;              ///< Type of textfile to view.
	Scrollbar *vscroll;                  ///< Vertical scrollbar.
	Scrollbar *hscroll;                  ///< Horizontal scrollbar.
	char *text;                          ///< Lines of text from the NewGRF's textfile.
	SmallVector<const char *, 64> lines; ///< #text, split into lines in a table with lines.
	uint search_iterator;                ///< Iterator for the font check search.

	static const int TOP_SPACING    = WD_FRAMETEXT_TOP;    ///< Additional spacing at the top of the #WID_TF_BACKGROUND widget.
	static const int BOTTOM_SPACING = WD_FRAMETEXT_BOTTOM; ///< Additional spacing at the bottom of the #WID_TF_BACKGROUND widget.

	TextfileWindow(TextfileType file_type);
	virtual ~TextfileWindow();
	virtual void UpdateWidgetSize(int widget, Dimension *size, const Dimension &padding, Dimension *fill, Dimension *resize);
	virtual void OnClick(Point pt, int widget, int click_count);
	virtual void DrawWidget(const Rect &r, int widget) const;
	virtual void OnResize();
	virtual void Reset();
	virtual FontSize DefaultSize();
	virtual const char *NextString();
	virtual bool Monospace();
	virtual void SetFontNames(FreeTypeSettings *settings, const char *font_name);
	virtual void LoadTextfile(const char *textfile, Subdirectory dir);
private:
	uint GetContentHeight();
	void SetupScrollbars();
};

#endif /* TEXTFILE_GUI_H */
