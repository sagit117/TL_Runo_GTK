#pragma once

#include <gtk/gtk.h>
#include "../headers/app.h"

#define RUNO_APP_WINDOW_TYPE runo_app_window_get_type()
G_DECLARE_FINAL_TYPE(RunoAppWindow, runo_app_window, RUNO, APP_WINDOW, GtkApplicationWindow)

RunoAppWindow *runo_app_window_new(RunoApp *app);