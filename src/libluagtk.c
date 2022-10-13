
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

	app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

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
