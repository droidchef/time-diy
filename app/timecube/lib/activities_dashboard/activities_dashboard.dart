import 'package:flutter/material.dart';

class ActivitiesDashboard extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Activities'),
      ),
      body: Center(
        child: ListView(
          children: <Widget>[
            buildCard(Colors.red, 'Side A'),
            buildCard(Colors.yellow, 'Side B'),
            buildCard(Colors.green, 'Side C'),
            buildCard(Colors.blue, 'Side D'),
            buildCard(Colors.purple, 'Side E'),
            buildCard(Colors.orange, 'Side F'),
          ],
        ),
      ),
    );
  }

  Card buildCard(Color color, String text) {
    return Card(
            child: Row(
              children: <Widget>[
                CircleAvatar(
                  backgroundColor: color,
                ),
                Text(text)
              ],
            ),
          );
  }
}
