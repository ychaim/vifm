/* vifm
 * Copyright (C) 2001 Ken Steen.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <limits.h>
#include <ncurses.h>

#define KEYPRESS_TIMEOUT 1000 /* 1 second */

typedef struct _Config {
	char config_dir[PATH_MAX];
	char trash_dir[PATH_MAX];
	char *vi_command;
	int num_bookmarks;
	int use_trash;
	int vim_filter;
	int use_screen;
	int use_vim_help;
	int command_num;
	int filetypes_num;
	int history_len;
	int nmapped_num;
	int screen_num;
	char **search_history;
	int search_history_len;
	int search_history_num;
	int auto_execute;
	int show_one_window;
	long max_args;
	int using_default_config;
	int use_iec_prefixes;
	int wrap_quick_view;
	char *time_format;
	char *fuse_home;

	char **cmd_history;
	int cmd_history_len;
	int cmd_history_num;

	int color_scheme_num;
	int color_pairs_num;
	int color_scheme_cur;

	int undo_levels; /* Maximum number of changes that can be undone. */

	int sort_numbers; /* Natural sort of (version) numbers within text. */
} Config;

extern Config cfg;

int read_config_file(void);
void write_config_file(void);
void set_config_dir(void);
void init_config(void);
void exec_startup(void);

#endif

/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab cinoptions-=(0 : */
