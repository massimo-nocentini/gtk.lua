
#$(pkg-config --cflags gtk4) \
#$(pkg-config --libs gtk4) \

linux:
	gcc -O2 -std=gnu99 -fPIC -Wall \
		-mfpmath=sse -msse -msse2 -pthread -I/usr/include/gtk-4.0 -I/usr/include/gio-unix-2.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/fribidi -I/usr/include/harfbuzz -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/x86_64-linux-gnu -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/graphene-1.0 -I/usr/lib/x86_64-linux-gnu/graphene-1.0/include -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
		-I/usr/local/include/ \
		-s -shared -o libluagtk.so libluagtk.c -L/usr/local/lib/ -llua -lgtk-4 -lpangocairo-1.0 -lpango-1.0 -lharfbuzz -lgdk_pixbuf-2.0 -lcairo-gobject -lcairo -lgraphene-1.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0

linux_manual:
	gcc -O2 -std=gnu99 -fPIC -Wall -g \
		-I/usr/include/gdk-pixbuf-2.0/ \
		-I/usr/include/graphene-1.0/ \
		-I/usr/lib/x86_64-linux-gnu/graphene-1.0/include/ \
		-I/usr/lib/x86_64-linux-gnu/glib-2.0/include/ \
		-I/usr/include/cairo/ \
		-I/usr/include/pango-1.0/ \
		-I/usr/include/harfbuzz \
		-I/usr/include/glib-2.0/ \
		-I/usr/include/gtk-4.0/ \
		-I/usr/local/include/ \
		-s -shared -o libluagtk.so libluagtk.c -L/usr/local/lib/ -llua -lgtk-4 -lpangocairo-1.0 -lpango-1.0 -lharfbuzz -lgdk_pixbuf-2.0 -lcairo-gobject -lcairo -lgraphene-1.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0

install:
	mkdir -p /usr/local/lib/lua/5.4/	# just for ensuring that the dest dir exists
	mkdir -p /usr/local/share/lua/5.4/	# just for ensuring that the dest dir exists
	mv libluagtk.so /usr/local/lib/lua/5.4/
	cp gtk.lua /usr/local/share/lua/5.4/
