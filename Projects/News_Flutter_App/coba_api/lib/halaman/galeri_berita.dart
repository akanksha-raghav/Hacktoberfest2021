import 'package:coba_api/api/api.dart';
import 'package:coba_api/api/data_list_berita/data.dart';
import 'package:coba_api/halaman/viewer.dart';
import 'package:flutter/material.dart';

class GaleriBerita extends StatefulWidget {
  const GaleriBerita({Key? key}) : super(key: key);

  @override
  _GaleriBeritaState createState() => _GaleriBeritaState();
}

class _GaleriBeritaState extends State<GaleriBerita> {
  var data = <Data>[];

  void _getListNews() async {
    Api.getListNews()
        .then((value) => {
              setState(() {
                data = value.data;
              })
            })
        .catchError((err) {
      print(err);
    });
  }

  @override
  void initState() {
    super.initState();
    _getListNews();
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      child: GridView.builder(
          itemCount: data.length,
          gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
            crossAxisCount: 2,
          ),
          itemBuilder: (context, index) {
            return GridTile(
                child: GestureDetector(
              onTap: () {
                Navigator.of(context).push(
                  MaterialPageRoute(
                    builder: (context) => Viewer(
                      judulNews: data[index].jdl_news,
                      imgUrl: data[index].foto_news,
                    ),
                  ),
                );
              },
              child: Container(
                padding: EdgeInsets.all(5),
                child: Center(
                  child: Image.network(
                    data[index].foto_news,
                    fit: BoxFit.cover,
                    width: 500,
                    height: 275,
                    loadingBuilder: (context, child, loadingProgress) {
                      if (loadingProgress == null) return child;
                      // expectedTotalBytes = total ukuran gambar
                      // cumulativeBytesLoaded = ukuran gambar yang sedang dimuat/load
                      return Center(
                        child: Container(
                          padding: EdgeInsets.all(15),
                          width: 80,
                          height: 80,
                          child: CircularProgressIndicator(
                            strokeWidth: 5.0,
                            value: (loadingProgress.expectedTotalBytes != null)
                                ? loadingProgress.cumulativeBytesLoaded /
                                    loadingProgress.expectedTotalBytes!
                                : null,
                          ),
                        ),
                      );
                    },
                  ),
                ),
              ),
            ));
          }),
    );
  }
}
