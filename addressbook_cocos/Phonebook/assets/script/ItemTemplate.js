// Learn cc.Class:
//  - https://docs.cocos.com/creator/manual/en/scripting/class.html
// Learn Attribute:
//  - https://docs.cocos.com/creator/manual/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - https://docs.cocos.com/creator/manual/en/scripting/life-cycle-callbacks.html

cc.Class({
    extends: cc.Component,

    properties: {
        id : 0,
        itemName : cc.Label,
        num : cc.Label,
       
    },

    init : function(data) {
        this.id = data.id;
        this.itemName = data.itemName;
        this.num = data.num;
       
    }

    
});
