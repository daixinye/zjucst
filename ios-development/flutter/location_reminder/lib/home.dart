import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';

class MyHomePage extends StatefulWidget {
  MyHomePage({Key key, this.title}) : super(key: key);

  // This widget is the home page of your application. It is stateful, meaning
  // that it has a State object (defined below) that contains fields that affect
  // how it looks.

  // This class is the configuration for the state. It holds the values (in this
  // case the title) provided by the parent (in this case the App widget) and
  // used by the build method of the State. Fields in a Widget subclass are
  // always marked "final".

  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  List<Reminder> _reminderItems = <Reminder>[];

  _MyHomePageState() {
    _reminderItems = List<Reminder>.generate(
        10, (i) => Reminder("Title $i", "Description $i"));
  }

  @override
  Widget build(BuildContext context) {
    return CupertinoPageScaffold(
      navigationBar: CupertinoNavigationBar(
        middle: Text('Location Reminder'),
        trailing: CupertinoButton(
          padding: EdgeInsets.all(0),
          child: Icon(Icons.add),
          onPressed: _addReminder,
        ),
      ),
      child: _buildReminders(),
    );
  }

  Widget _buildReminders() {
    return ListView.builder(
        padding: const EdgeInsets.all(16.0),
        itemCount: _reminderItems.length,
        itemBuilder: (context, i) {
          return Column(children: <Widget>[
            _buildRow(_reminderItems[i]),
            Divider(),
          ]);
        });
  }

  Widget _buildRow(item) {
    return Row(
      children: <Widget>[
        Expanded(
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Container(
                padding: const EdgeInsets.only(bottom: 8.0),
                child: Text(
                  item.title,
                  style: TextStyle(
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ),
              Text(
                item.description,
                style: TextStyle(
                  color: Colors.grey[500],
                ),
              ),
            ],
          ),
        ),
        CupertinoSwitch(
          onChanged: (state){
            setState((){
              item.toggle = state;
            });
          },
          value: item.toggle
        )
      ],
    );
  }

  void _addReminder() {
    setState(() {
      _reminderItems.add(Reminder("Test", "test"));
    });
  }
}

class Reminder {
  String title;
  String description;
  bool toggle = true;

  Reminder(this.title, this.description);
}
