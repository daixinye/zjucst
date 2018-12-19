import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

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
  // Create a global key that will uniquely identify the Form widget and allow
  // us to validate the form
  //
  // Note: This is a `GlobalKey<FormState>`, not a GlobalKey<MyCustomFormState>!
  final _formKey = GlobalKey<FormState>();
  String _title = "title";
  String _description = "description";

  @override
  Widget build(BuildContext context) {
    // Build a Form widget using the _formKey we created above
    return Form(
      key: _formKey,
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: <Widget>[
          CupertinoTextField(
            prefix: Text('标题：'),
            onChanged: (text) {
              _title = text;
            },
          ),
          CupertinoTextField(
            prefix: Text('描述：'),
            onChanged: (text) {
              _description = text;
            },
          ),
          Padding(
            padding: const EdgeInsets.symmetric(vertical: 16.0),
            child: CupertinoButton(
              onPressed: () {
                Navigator.pop(
                    context, {"title": _title, "description": _description});
              },
              child: Text('Submit'),
            ),
          ),
        ],
      ),
    );
  }
}
