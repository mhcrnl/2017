/* gtd-task-row.h
 *
 * Copyright (C) 2015 Georges Basile Stavracas Neto <georges.stavracas@gmail.com>
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
 */

#ifndef GTD_TASK_ROW_H
#define GTD_TASK_ROW_H

#include "gtd-types.h"

#include <glib-object.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GTD_TYPE_TASK_ROW (gtd_task_row_get_type())

G_DECLARE_FINAL_TYPE (GtdTaskRow, gtd_task_row, GTD, TASK_ROW, GtkListBoxRow)

GtkWidget*                gtd_task_row_new                      (GtdTask             *task);

gboolean                  gtd_task_row_get_new_task_mode        (GtdTaskRow          *row);

void                      gtd_task_row_set_new_task_mode        (GtdTaskRow          *row,
                                                                 gboolean             new_task_mode);

GtdTask*                  gtd_task_row_get_task                 (GtdTaskRow          *row);

void                      gtd_task_row_set_task                 (GtdTaskRow          *row,
                                                                 GtdTask             *task);

void                      gtd_task_row_set_list_name_visible    (GtdTaskRow          *row,
                                                                 gboolean             show_list_name);

void                      gtd_task_row_reveal                   (GtdTaskRow          *row);

void                      gtd_task_row_destroy                  (GtdTaskRow          *row);

G_END_DECLS

#endif /* GTD_TASK_ROW_H */
