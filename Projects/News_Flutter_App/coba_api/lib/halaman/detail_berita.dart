import 'package:coba_api/api/data_detail_berita/detail_berita_response.dart';
import 'package:flutter/material.dart';
import 'package:coba_api/api/api.dart';

class DetailBerita extends StatefulWidget {
  final String id;
  const DetailBerita({Key? key, required this.id}) : super(key: key);

  @override
  _DetailBerita createState() => _DetailBerita();
}

class _DetailBerita extends State<DetailBerita> {
  //late DetailBeritaResponse data;
  String foto = "", judul = "", tanggal = "", ketnews = "";

  void _getDetailBerita() async {
    Api.getDetailNews(widget.id).then((value) {
      setState(() {
        foto = value.foto_news;
        judul = value.jdl_news;
        ketnews = value.ket_news;
        tanggal = value.post_on;
      });
    }).catchError((err) {
      print(err);
    });
  }

  @override
  void initState() {
    _getDetailBerita();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
          title: Center(
        child: Text("Detail Berita"),
      )),
      body: Padding(
        padding: EdgeInsets.all(25),
        child: SingleChildScrollView(
          child: Column(
            children: [
              SizedBox(
                height: 20,
              ),
              Column(),
              Card(
                semanticContainer: true,
                clipBehavior: Clip.antiAliasWithSaveLayer,
                child: Image.network(
                  foto,
                  fit: BoxFit.fitWidth,
                ),
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(15.0),
                ),
                elevation: 5,
                margin: EdgeInsets.only(bottom: 10),
              ),
              Align(
                alignment: Alignment.topLeft,
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Text(
                      judul,
                      style:
                          TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
                    ),
                    Text(
                      tanggal,
                      style: TextStyle(fontSize: 12),
                    ),
                    SizedBox(
                      height: 18,
                    ),
                    Text(
                      ketnews,
                      style: TextStyle(fontSize: 14),
                    ),
                  ],
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
