#include "http.h"

#include <curl/curl.h>
#include <stdio.h>

//TODO: Allow for streaming & redirects
int
save (const char *site, const char *fn)
{
  CURLcode ret;
  CURL *hnd;
  if (!hnd)
    {
      return -1; /* error, cURL not availing */
    }

  hnd = curl_easy_init ();

  FILE *fp = fopen (fn, "wb");

  if (!fp)
    return -1; // error, where's the file?

  curl_easy_setopt (hnd, CURLOPT_BUFFERSIZE, 102400L);
  curl_easy_setopt (hnd, CURLOPT_URL, site);
  curl_easy_setopt (hnd, CURLOPT_NOPROGRESS, 1L);
  curl_easy_setopt (hnd, CURLOPT_USERAGENT, "curl/7.81.0");
  curl_easy_setopt (hnd, CURLOPT_MAXREDIRS, 50L);
  curl_easy_setopt (hnd, CURLOPT_WRITEDATA, fp);
  curl_easy_setopt (hnd, CURLOPT_WRITEFUNCTION, NULL);
  curl_easy_setopt (hnd, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
  curl_easy_setopt (hnd, CURLOPT_FTP_SKIP_PASV_IP, 1L);
  curl_easy_setopt (hnd, CURLOPT_TCP_KEEPALIVE, 1L);

  ret = curl_easy_perform (hnd);

  curl_easy_cleanup (hnd);
  hnd = NULL;

  return (int)ret;
}