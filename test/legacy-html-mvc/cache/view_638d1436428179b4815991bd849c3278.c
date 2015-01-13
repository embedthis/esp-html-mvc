/*
   Generated from app/post/post-list.esp
 */
#include "esp.h"

static void view_638d1436428179b4815991bd849c3278(HttpConn *conn) {
EdiGrid     *grid = readTable("post");
    EdiRec      *rec;
    EdiField    *fp;
  
  espRenderBlock(conn, "<!DOCTYPE html>\n\
<html lang=\"en\">\n\
<head>\n\
    <title></title>\n\
    <meta charset=\"utf-8\" />\n\
    <link rel=\"icon\" href=\"", 116);
  espRenderString(conn, conn->rx->route->prefix);  espRenderBlock(conn, "/assets/favicon.ico\" type=\"image/x-icon\">\n\
    <link href=\"", 58);
  espRenderString(conn, conn->rx->route->prefix);  espRenderBlock(conn, "/css/all.css\" rel=\"stylesheet\" type=\"text/css\" />\n\
</head>\n\
<body id='body' data-config='", 87);
renderConfig();   espRenderBlock(conn, "'>\n\
    <nav class=\"navbar\">\n\
        <div class=\"navbar-header\">\n\
            <a class=\"navbar-brand\" href=\"", 106);
  espRenderString(conn, conn->rx->route->prefix);  espRenderBlock(conn, "\">Home</a>\n\
        </div>\n\
    </nav>\n\
    <main class=\"container\">\n\
        <section class=\"content col-md-10\" id=\"content\">\n\
            ", 135);
  espRenderBlock(conn, "\n\
<h1>Post List</h1>\n\
<table class='list'>\n\
    <thead>\n\
        <tr>", 65);
if (grid && grid->nrecords) {
                rec = grid->records[0];
                for (fp = 0; (fp = ediGetNextField(rec, fp, 1)) != 0; ) { 
                    render("<th>%s</th>\n", stitle(fp->name));
                }
            }   espRenderBlock(conn, "\n\
        </tr>\n\
    </thead>\n\
    <tbody>\n\
        ", 48);
for (rec = 0; (rec = ediGetNextRec(grid, rec)) != 0; ) {   espRenderBlock(conn, "\n\
            <tr onclick='document.location=\"", 45);
  espRenderSafeString(conn, uri("|/post/%s", rec->id));
  espRenderBlock(conn, "\"'>\n\
                ", 20);
for (fp = 0; (fp = ediGetNextField(rec, fp, 1)) != 0; ) {   espRenderBlock(conn, "\n\
                    <td>", 25);
  espRenderSafeString(conn, ediFormatField(0, fp));
  espRenderBlock(conn, "</td>\n\
                ", 22);
}   espRenderBlock(conn, "\n\
            </tr>\n\
        ", 27);
}   espRenderBlock(conn, "\n\
    </tbody>\n\
</table>\n\
<a href=\"init\"><button class='btn btn-primary'>New Post</button></a>\n\
", 92);
  espRenderBlock(conn, "\n\
        </section>\n\
        <div class=\"feedback\">\n\
            ", 63);
renderFlash("all");   espRenderBlock(conn, "\n\
        </div>\n\
    </main>\n\
</body>\n\
</html>\n\
", 44);
}

ESP_EXPORT int esp_view_638d1436428179b4815991bd849c3278(HttpRoute *route, MprModule *module) {
   espDefineView(route, "app/post/post-list.esp", view_638d1436428179b4815991bd849c3278);
   return 0;
}
