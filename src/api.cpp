#include "api.h"

API::API() {}
API::~API() {}

void API::setHttp(HTTPClient &objH)
{
  this->objHttp = &objH;
}

void API::create(String name, int value)
{
  String url = hostServer + "/sensor";
  String data =
              "{"
              " \"name\" : \""+ name +"\", "
              " \"value\" : \""+ value +"\" "
              "}";

  sendRequest(url, data, "POST");
}

boolean API::sendRequest(String url, String data, String type)
{
  try
  {
    boolean status = false;
    int httpCode;

    objHttp->begin(url);
    objHttp->addHeader("Content-Type", "application/json");
    
    if (type == "POST") {
      httpCode = objHttp->POST(data);
    } else {
      httpCode = 0;
    }

    // Serial.println(objHttp->getString());

    status = (httpCode > 0 && httpCode == HTTP_CODE_OK);

    objHttp->end();
    return status;
  }
  catch (...)
  {
    return false;
  }
}
