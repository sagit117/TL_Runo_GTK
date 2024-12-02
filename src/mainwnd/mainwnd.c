#include "../headers/mainwnd.h"
#include "../headers/app_menu.h"
#include "../headers/app.h"

struct _RunoAppWindow
{
    GtkApplicationWindow parent;
    GtkWidget *stack;
};

G_DEFINE_TYPE(RunoAppWindow, runo_app_window, GTK_TYPE_APPLICATION_WINDOW)

static void runo_app_window_init(RunoAppWindow *win) {
    gtk_widget_init_template(GTK_WIDGET(win));
}


static void runo_app_window_class_init(RunoAppWindowClass *class) {
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class), "/ru/axel/tl/mainwnd.ui");
    // gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class), RunoAppWindow, stack);
}

RunoAppWindow *runo_app_window_new(RunoApp *app) {
    return g_object_new(RUNO_APP_WINDOW_TYPE, "application", app, NULL);
}


/** 
 * Метод активации главного окна.
 * @param app объект приложения.
 * @param _user_data параметры.
 */
void activate_mainwnd(GtkApplication *app, gpointer _user_data) {
    GtkBuilder *builder = gtk_builder_new_from_file("./src/mainwnd/mainwnd.ui");
    GObject *window = gtk_builder_get_object(builder, "window");

    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_widget_set_visible(GTK_WIDGET(window), TRUE);
    // gtk_window_maximize(GTK_WINDOW(window));

    GObject *button_app_menu = gtk_builder_get_object(builder, "app_menu_btn");
    set_app_menu_model(GTK_MENU_BUTTON(button_app_menu), app);

    g_object_unref(builder);
}