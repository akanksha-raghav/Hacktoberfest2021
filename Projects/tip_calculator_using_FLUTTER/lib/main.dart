import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  final controller = TextEditingController();

  List<bool> _selection = [true, false, false];
  String tip = '';

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              if (tip != null)
                Padding(
                  padding: EdgeInsets.all(20),
                  child: Text(
                    tip,
                    style: TextStyle(fontSize: 30, fontFamily: 'Serrat'),
                  ),
                ),
              Text(
                'Total Amount',
                style: TextStyle(fontFamily: 'Serrat'),
              ),
              SizedBox(
                width: 70,
                child: TextField(
                  style: TextStyle(fontFamily: 'Serrat'),
                  controller: controller,
                  textAlign: TextAlign.center,
                  decoration: InputDecoration(hintText: '\$100.00'),
                  keyboardType: TextInputType.numberWithOptions(decimal: true),
                  // style: ,
                ),
              ),
              SizedBox(height: 20),
              ToggleButtons(
                children: [
                  Text(
                    '10%',
                    style: TextStyle(fontFamily: 'Serrat'),
                  ),
                  Text(
                    '15%',
                    style: TextStyle(fontFamily: 'Serrat'),
                  ),
                  Text(
                    '20%',
                    style: TextStyle(fontFamily: 'Serrat'),
                  ),
                ],
                isSelected: _selection,
                onPressed: updateSelection,
                borderRadius: BorderRadius.all(Radius.circular(10)),
              ),
              SizedBox(height: 20),
              FlatButton(
                onPressed: calculateTip,
                child: Text(
                  'Calculate Tip',
                  style: TextStyle(fontFamily: 'Serrat'),
                ),
                color: Colors.green,
                textColor: Colors.white,
              )
            ],
          ),
        ),
      ),
    );
  }

  void updateSelection(int selectedIndex) {
    setState(() {
      for (int i = 0; i < _selection.length; i++) {
        _selection[i] = selectedIndex == i;
      }
    });
  }

  void calculateTip() {
    final totalAmount = double.parse(controller.text);
    final selectedIndex = _selection.indexWhere((element) => element);
    final tipPercentage = [0.1, 0.15, 0.2][selectedIndex];

    final tipTotal = (totalAmount * tipPercentage).toStringAsFixed(2);
    setState(() {
      tip = '\$$tipTotal';
    });
  }
}
