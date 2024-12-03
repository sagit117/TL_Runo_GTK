#include "../headers/mainwnd.h"
#include "../headers/app.h"

struct _RunoAppWindow
{
    GtkApplicationWindow parent;

    GtkWidget *gears;
};

G_DEFINE_TYPE(RunoAppWindow, runo_app_window, GTK_TYPE_APPLICATION_WINDOW)

static void runo_app_window_init(RunoAppWindow *win) {
    GtkBuilder *builder;
    GMenuModel *menu;

    gtk_widget_init_template(GTK_WIDGET(win));

    builder = gtk_builder_new_from_resource("/ru/axel/tl/app_menu.ui");
    menu = G_MENU_MODEL(gtk_builder_get_object(builder, "app_menu"));
    gtk_menu_button_set_menu_model(GTK_MENU_BUTTON(win->gears), menu);
    g_object_unref(builder);
}

static void runo_app_window_class_init(RunoAppWindowClass *class) {
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class), "/ru/axel/tl/mainwnd.ui");
    // gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class), RunoAppWindow, stack);
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class), RunoAppWindow, gears);
}

RunoAppWindow *runo_app_window_new(RunoApp *app) {
    return g_object_new(RUNO_APP_WINDOW_TYPE, "application", app, NULL);
}