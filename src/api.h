#ifndef API_H_
#define API_H_

#include "libs.h"

class API{
   HTTPClient *objHttp = new HTTPClient();

   String hostServer = HOST_SERVER;
public:
   API();
   virtual ~API();

   void setHttp(HTTPClient &objH);

   void create(String name, int value);

   boolean sendRequest(String url, String data, String type);
};

#endif /*API_H_*/
