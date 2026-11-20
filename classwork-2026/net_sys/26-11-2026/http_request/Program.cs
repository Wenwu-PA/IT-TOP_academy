// #pragma warning disable SYSLIB0014

using System.Net;
// HttpWebRequest request = (HttpWebRequest)WebRequest.Create("https://wiki.archlinux.org");
// request.GetResponse();

using HttpClient client = new HttpClient();
client.DefaultRequestHeaders.Add("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3");

string url = "https://wiki.archlinux.org";
string result = await client.GetStringAsync(url);
Console.WriteLine(result);