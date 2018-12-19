import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'screen_item.dart';
import 'utils/location.dart';
import 'utils/notification.dart';
import 'utils/calculator.dart';

class MyHomePage extends StatefulWidget {
  MyHomePage({Key key, this.title}) : super(key: key);
  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  List<Reminder> _reminderItems = <Reminder>[
    Reminder(
      '学校蜂巢快递柜',
      '取快递，取号码：0180',
      29.8912481909,
      121.6399598122,
    ),
    Reminder('永辉超市', '买纸巾、洗发水', 29.8923364733, 121.6553878784),
    Reminder('实验室', '拿一下电脑充电器', 29.8902203577, 121.6401636600),
    Reminder('寝室楼下', '看一下水费和电费要不要交', 29.8909877455, 121.6358828545)
  ];
  var _currentLatitude = -1.0;
  var _currentLongitude = -1.0;

  @override
  void initState() {
    super.initState();

    MyLocation.initLocation(this.onLocation);
  }

  void onLocation(location) {
    var latitude = location.coords.latitude;
    var longitude = location.coords.longitude;

    _reminderItems.forEach((item) {
      var currentDistance = MyCalculator.getDistance(
          item.latitude, item.longitude, latitude, longitude);
      if (currentDistance < item.distance && item.toggle) {
        print('到达${item.title}附近');
        MyNotification.show('到达${item.title}附近', '${item.description}', '');
      }
    });

    setState(() {
      _currentLatitude = latitude;
      _currentLongitude = longitude;
    });
  }

  @override
  Widget build(BuildContext context) {
    return CupertinoPageScaffold(
      navigationBar: CupertinoNavigationBar(
        middle: Text('Location Reminder'),
        trailing: CupertinoButton(
          padding: EdgeInsets.all(0),
          child: Icon(Icons.add),
          onPressed: () async {
            final result = await Navigator.push(context,
                CupertinoPageRoute(builder: (context) => ItemAddScreen()));

            if (result != null) {
              String title = result["title"];
              String description = result["description"];
              var latitude = result["latitude"];
              var longitude = result["longitude"];

              setState(() {
                _reminderItems.add(
                    Reminder("$title", "$description", latitude, longitude));
              });
            }
          },
        ),
      ),
      child: Container(
        margin: const EdgeInsets.fromLTRB(0, 80, 0, 0),
        child: _buildReminders(),
      ),
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
                child: Row(
                  children: <Widget>[
                    Text(
                      item.title,
                      style: TextStyle(
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                    Text(
                      item.toggle
                          ? " ${MyCalculator.getDistance(item.latitude, item.longitude, _currentLatitude, _currentLongitude)}m"
                          : "",
                      style: TextStyle(
                        fontSize: 10,
                        color: Colors.grey,
                      ),
                    )
                  ],
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
            onChanged: (state) {
              setState(() {
                item.toggle = state;
              });
            },
            value: item.toggle)
      ],
    );
  }
}

class Reminder {
  String title;
  String description;
  var latitude;
  var longitude;
  var distance = 500;

  bool toggle = true;

  Reminder(this.title, this.description, this.latitude, this.longitude);
}
