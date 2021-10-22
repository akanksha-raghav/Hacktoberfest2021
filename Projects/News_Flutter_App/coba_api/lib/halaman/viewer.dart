import 'package:flutter/material.dart';
import 'package:photo_view/photo_view.dart';

class Viewer extends StatelessWidget {
  final String judulNews;
  final String imgUrl;
  const Viewer(
      {Key? key,
      required this.judulNews,
      this.imgUrl =
          "https://rimatour.com/wp-content/uploads/2017/09/No-image-found.jpg"})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(judulNews),
      ),
      body: Container(
        child: PhotoView(
          backgroundDecoration: BoxDecoration(color: Colors.transparent),
          imageProvider: NetworkImage(imgUrl),
        ),
      ),
    );
  }
}
