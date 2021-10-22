import 'package:coba_api/halaman/galeri_berita.dart';
import 'package:coba_api/halaman/list_berita.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(BeritaLauwba());
}

class BeritaLauwba extends StatelessWidget {
  const BeritaLauwba({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "Berita Lauwba",
      theme: ThemeData(primarySwatch: Colors.blue),
      debugShowCheckedModeBanner: false,
      home: Mainscreen(),
    );
  }
}

class Mainscreen extends StatefulWidget {
  const Mainscreen({Key? key}) : super(key: key);

  @override
  _MainscreenState createState() => _MainscreenState();
}

class _MainscreenState extends State<Mainscreen> {
  @override
  Widget build(BuildContext context) {
    return DefaultTabController(
        length: 2,
        child: Scaffold(
          appBar: AppBar(
            title: Text("Coba API Berita"),
          ),
          body: TabBarView(
            children: [
              ListBerita(),
              GaleriBerita(),
            ],
          ),
          bottomNavigationBar: TabBar(
            labelColor: Colors.green,
            unselectedLabelColor: Colors.black26,
            indicatorColor: Colors.transparent,
            tabs: [
              Tab(
                icon: Icon(Icons.language),
              ),
              Tab(
                icon: Icon(Icons.photo_library),
              ),
            ],
          ),
        ));
  }
}
