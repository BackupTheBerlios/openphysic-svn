var direction = true; // true=bas false=haut
var scroll = true;

var delay=100;
var step=5;

var obj=null;

function pageScroll() {
  scrolldelay = setTimeout('pageScroll()', delay); // scrolls every 1000 milliseconds

  set_scrollable(document.body);

  if (scroll) {
    if ( bottom() )
      direction=false;

    if ( top() )
      direction=true;

    if ( direction ) {
      window.scrollBy(0, step);
    } else {
      window.scrollBy(0, -step);    
    }
  }
}

function bottom()
{
  if ( (obj.scrollTop + obj.clientHeight) == obj.scrollHeight ) {
    return true;
  } else {
    return false;
  }
}

function top()
{
  if ( obj.scrollTop==0 ) {
    return true;
  } else {
    return false;
  }
}

function set_scrollable(new_obj) {
  obj=new_obj;
}
