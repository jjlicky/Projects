cc.Class({
    extends: cc.Component,
    properties: {
        id: 0,
        itemName: cc.Label,
        itemPrice: cc.Label
    },

    init: function (data) {
        this.id = data.id;
        this.itemName.string = data.itemName;
        this.itemPrice.string = data.itemPrice;
    }
});