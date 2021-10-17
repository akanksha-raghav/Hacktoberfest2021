import 'package:http/http.dart' as http;
import 'dart:convert';
import 'data_list_berita/list_berita_response.dart';
import 'data_detail_berita/detail_berita_response.dart';

const baseUrl = "https://lauwba.com/webservices/";

class Api {
  static Future<ListBeritaResponse> getListNews() async {
    var url = baseUrl + "get_latest_news";
    final response = await http.get(Uri.parse(url));
    if (response.statusCode == 200) {
      return ListBeritaResponse.fromJsonMap(jsonDecode(response.body));
    } else {
      throw "failed to get lis news";
    }
  }

  static Future<DetailBeritaResponse> getDetailNews(String idNews) async {
    var url = baseUrl + "get_detail_news/$idNews";
    final response = await http.get(Uri.parse(url));
    if (response.statusCode == 200) {
      return DetailBeritaResponse.fromJsonMap(jsonDecode(response.body));
    } else {
      throw "failed to get detail news";
    }
  }
}
