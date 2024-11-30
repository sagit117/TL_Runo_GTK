#pragma once

#include "gtk/gtk.h"

/**
 * Привязка кнопки к меню приложения.
 * @param button кнопка меню.
 * @param app объект приложения.
 */
void set_app_menu_model(GtkMenuButton *button, GtkApplication *app);