
/* 
	This is a glue c file for importing delta client c functions into Lua workflow.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <lua.h>
#include <lauxlib.h>
#include <time.h>

#include <gtk/gtk.h>

/* Callback that will be called when the application is activated */
static void
activate_callback(GApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *label;

    /* Create the main, top level window */
    window = gtk_window_new();

    /* Give it the title */
    gtk_window_set_title(GTK_WINDOW(window), "Hello, world!");

    /* Set the window's default size */
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    /* Assign the variable "label" to a new GTK label,
     * with the text "Hello, world!" */
    label = gtk_label_new("Hello, world!");

    /* Plot the label onto the main window */
    gtk_window_set_child(GTK_WINDOW(window), label);

    /* Make the application aware of the window.
     * The application process will continue to run until all
     * windows are closed */
    gtk_application_add_window(GTK_APPLICATION(app), GTK_WINDOW(window));

    /* Make sure that everything, window and label, are visible */
    gtk_widget_show(window);
}

static void activate (GtkApplication* app, gpointer        user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  gtk_widget_show (window);
}

static int l_run(lua_State *L) {

	int    argc = 0;
	char **argv = NULL;
	GtkApplication *app;
	int status;

	/*
	app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);
	*/

	 /* Create our test application */
    GtkApplication *application = gtk_application_new("org.wikipedia.gtktest", 0);

    /* Connect our handler to the "activate" callback, which will be called
     * when the application is activated by the user, e.g. on first start */
    g_signal_connect(application, "activate", G_CALLBACK(activate_callback), NULL);

    /* Run the application and return its status */
    status = g_application_run(G_APPLICATION(application), argc, argv);

	lua_pushinteger(L, status);

	return 1;
	
}

static const struct luaL_Reg gtk_lib [] = {
	{"run", l_run},
	{NULL, NULL} /* sentinel */
};
 
int luaopen_libluagtk (lua_State *L) {
	luaL_newlib(L, gtk_lib);
	return 1;
}
