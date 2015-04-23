#include <bson.h>
#include <mongoc.h>
#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    mongoc_cursor_t *cursor;
    const bson_t *doc;
    bson_t *query;
    char *str;

    mongoc_init ();

    client = mongoc_client_new ("mongodb://exam:27017/");
    collection = mongoc_client_get_collection (client, "wfilter", "words");
    query = bson_new ();
    cursor = mongoc_collection_find (collection, MONGOC_QUERY_NONE, 0, 0, 0, query, NULL, NULL);

    while (mongoc_cursor_next (cursor, &doc)) {
#if 0
        bson_iter_t iter;
        //bson_iter_t child;
        //bson_t *b;
        if (bson_iter_init (&iter, doc)) {
                while (bson_iter_next (&iter)) {
                 //b = bson_iter_value(&iter);
                 //
                 printf ("Found element key: \"%s\"  %s\n", bson_iter_key (&iter), bson_iter_utf8(&iter, NULL));

           }
        } 
#endif
        bson_iter_t iter;
        if (bson_iter_init (&iter, doc) && bson_iter_find (&iter, "keyword")) {
             printf ("Found element key: \"%s\": %s\n", bson_iter_key (&iter), bson_iter_utf8(&iter, NULL));
        } 

        str = bson_as_json (doc, NULL);
        printf ("%s\n", str);
        bson_free (str);
    }

    bson_destroy (query);
    mongoc_cursor_destroy (cursor);
    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);

    return 0;
}