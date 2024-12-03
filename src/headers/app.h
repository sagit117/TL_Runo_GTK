#pragma once

#include <gtk/gtk.h>

#define RUNO_APP_TYPE runo_app_get_type()

G_DECLARE_FINAL_TYPE (RunoApp, runo_app, RUNO, APP, GtkApplication);

RunoApp *runo_app_new(void);