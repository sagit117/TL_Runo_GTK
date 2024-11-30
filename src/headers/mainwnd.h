#pragma once

#include <gtk/gtk.h>

/** 
 * Метод активации главного окна.
 * @param app объект приложения.
 * @param _user_data параметры.
 */
void activate_mainwnd(GtkApplication *app, gpointer _user_data);