import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:location/location.dart';
import 'utils/notification.dart';

class ItemAddScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return CupertinoPageScaffold(
      navigationBar: CupertinoNavigationBar(
        middle: Text('Add Reminder'),
      ),
      child: Container(
        margin: const EdgeInsets.fromLTRB(0, 100, 0, 0),
        child: MyCustomForm(),
      ),
    );
  }
}

class MyCustomForm extends StatefulWidget {
  @override
  MyCustomFormState createState() {
    return MyCustomFormState();
  }
}

class MyCustomFormState extends State<MyCustomForm> {
  final _formKey = GlobalKey<FormState>();
  String _title = "";
  String _description = "";
  var _latitude;
  var _longitude;
  var _currentLocation = <String, double>{};

  initLocation() async {
    var location = new Location();
    var currentLocation = await location.getLocation();

    setState(() {
      _currentLocation = currentLocation;
      print(_currentLocation);
      _latitude = _currentLocation["latitude"];
      _longitude = _currentLocation["longitude"];
    });
  }

  @override
  void initState() {
    super.initState();
    initLocation();
  }

  @override
  Widget build(BuildContext context) {
    return Form(
      key: _formKey,
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: <Widget>[
          Padding(
            padding: const EdgeInsets.all(0.0),
            child: Column(
              children: <Widget>[
                Text('地点名称',textAlign: TextAlign.left,),
                Divider(height: 10,indent: 2000,),
                CupertinoTextField(
                  placeholder: '如寝室、教学楼...',
                  onChanged: (text) {
                    _title = text;
                  },
                ),
                Divider(height: 20,indent: 2000,),
                Text('提醒事项'),
                Divider(height: 10,indent: 2000,),
                CupertinoTextField(
                  placeholder: '如拿钥匙、拿书...',
                  onChanged: (text) {
                    _description = text;
                  },
                ),
                Divider(height: 20,indent: 2000,),
                Text('触发距离'),
                Divider(height: 10,indent: 2000,),
                CupertinoTextField(
                  placeholder: '当在距离该地方多远时进行提醒，如500(m)',
                  onChanged: (text) {
                    _description = text;
                  },
                ),
                Divider(height: 50,indent: 2000,),
                CupertinoTextField(
                  prefix: Text(' 经度：'),
                  placeholder: "$_longitude",
                  onChanged: (text) {
                    _latitude = text;
                  },
                ),
                CupertinoTextField(
                  prefix: Text(' 纬度：'),
                  placeholder: "$_latitude",
                  onChanged: (text) {
                    _longitude = text;
                  },
                ),
              ],
            ),
          ),
          Center(
            child: CupertinoButton(
              onPressed: () {
                Navigator.pop(context, {
                  "title": _title,
                  "description": _description,
                  "latitude": _latitude,
                  "longitude": _longitude
                });
              },
              child: Text('添加'),
            ),
          ),
        ],
      ),
    );
  }
}
