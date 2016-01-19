if (Meteor.isClient) {
  // counter starts at 0
  Session.setDefault('counter', 0);

  Template.hello.helpers({
    counter: function () {
      return Session.get('counter');
    }
  });

  Template.hello.events({
    'click button': function () {
      // increment the counter when button is clicked
      Session.set('counter', Session.get('counter') + 1);
      me = FacebookCollections.getPosts("me",["type","picture"],20);

      Deps.autorun(function(){
          var posts = me.find().fetch();
          //console.log(posts);
          for (var p in posts){
            x ="<img src='" + posts[p].picture + "' /><br>"
            document.getElementById("test").innerHTML += x ; 
          }
          

          
      })
    }
  });

  Accounts.ui.config({
    requestPermissions: {
       facebook: ['user_photos', 'user_posts'],
    }
  });
}

if (Meteor.isServer) {
  Meteor.startup(function () {
    // code to run on server at startup
  });
}
