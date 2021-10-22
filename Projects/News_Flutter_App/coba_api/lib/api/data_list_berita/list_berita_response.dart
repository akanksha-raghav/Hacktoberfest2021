import 'package:coba_api/api/data_list_berita/data.dart';

class ListBeritaResponse {
  List<Data> data;
  String message;
  int error;

  // Konversi json ke map
  ListBeritaResponse.fromJsonMap(Map<String, dynamic> map)
      : data = List<Data>.from(map["data"].map((it) => Data.fromJsonMap(it))),
        message = map["message"],
        error = map["error"];

  // Konversi ke json, kemudian json disubmit ke web service
  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = new Map<String, dynamic>();
    data['data'] =
        data != null ? this.data.map((v) => v.toJson()).toList() : null;
    data['message'] = message;
    data['error'] = error;
    return data;
  }
}
