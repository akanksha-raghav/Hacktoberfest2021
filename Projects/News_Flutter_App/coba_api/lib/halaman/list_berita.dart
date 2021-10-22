import 'package:coba_api/halaman/detail_berita.dart';
import 'package:flutter/material.dart';
import 'package:coba_api/api/api.dart';
import 'package:coba_api/api/data_list_berita/data.dart';

class ListBerita extends StatefulWidget {
  @override
  _GetListBerita createState() => _GetListBerita();
}

class _GetListBerita extends State<ListBerita> {
  var _data = <Data>[];
  var _foundUsers = <Data>[];

  void _getBerita() async {
    Api.getListNews().then((value) {
      setState(() {
        _data = value.data;
        _foundUsers = _data;
        //print(_data);
      });
    }).catchError((err) {
      print(err);
    });
  }

  @override
  initState() {
    super.initState();
    _getBerita();
  }

  void _runFilter(String enteredKeyword) {
    var results = <Data>[];
    if (enteredKeyword.isEmpty) {
      results = _data;
    } else {
      results = _data
          .where((user) => user.jdl_news
              .toLowerCase()
              .contains(enteredKeyword.toLowerCase()))
          .toList();
    }

    setState(() {
      _foundUsers = results;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Padding(
        padding: const EdgeInsets.all(20),
        child: Column(
          children: [
            SizedBox(
              height: 20,
            ),
            TextField(
              onChanged: (value) => _runFilter(value),
              decoration: InputDecoration(
                  labelText: 'Search', suffixIcon: Icon(Icons.search)),
            ),
            SizedBox(
              height: 20,
            ),
            Expanded(
              child: _foundUsers.length > 0
                  ? ListView.builder(
                      itemCount: _foundUsers.length,
                      itemBuilder: (context, index) {
                        return Card(
                          color: Colors.amberAccent,
                          elevation: 4,
                          margin: EdgeInsets.symmetric(vertical: 7),
                          child: ListTile(
                              onTap: () {
                                Navigator.push(
                                  context,
                                  MaterialPageRoute(
                                    builder: (context) => DetailBerita(
                                        id: _foundUsers[index].id.toString()),
                                  ),
                                );
                              },
                              title: Text(
                                _foundUsers[index].jdl_news,
                                maxLines: 2,
                              ),
                              subtitle: Text(_foundUsers[index].post_on),
                              leading: CircleAvatar(
                                backgroundImage:
                                    NetworkImage(_foundUsers[index].foto_news),
                              ),
                              trailing: Icon(Icons.favorite)),
                        );
                      })
                  : Text(
                      'Data tidak ada!',
                      style: TextStyle(fontSize: 18),
                    ),
            ),
          ],
        ),
      ),
    );
  }
}
