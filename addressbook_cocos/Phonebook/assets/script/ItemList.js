// Learn cc.Class:
//  - https://docs.cocos.com/creator/manual/en/scripting/class.html
// Learn Attribute:
//  - https://docs.cocos.com/creator/manual/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - https://docs.cocos.com/creator/manual/en/scripting/life-cycle-callbacks.html

var Item = cc.Class({
    name: 'Item',
    properties: {
        name: '',
        num: ''
    }
});

cc.Class({
    extends: cc.Component,

    properties: {
      items: {
          default : [],
          type : Item
      }
    },
});
