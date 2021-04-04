var Item = cc.Class({
    name: 'Item',
    properties: {
        id: 0,
        itemName: '',
        itemPrice: ''
    }
});

cc.Class({
    extends: cc.Component,

    properties: {
        itemPrefab: cc.Prefab,
        names: [cc.String],
        numbers: [cc.String],
        scrollView: {
            default: null,
            type: cc.ScrollView
        },
        items: {
            default: [],
            type: Item
        },

        nameEditBox: {
            default: null,
            type: cc.EditBox
        },

        numberEditBox: {
            default: null,
            type: cc.EditBox
        },

        findEditBox: {
            default: null,
            type: cc.EditBox
        },

        popUp: {
            default : null,
            type: cc.Label
        },
        btn: cc.Button,
    },

    
    onLoad () {
        this.nameEditBox.node.on('editing-did-ended', this.nameEditboxCallback, this);
        this.numberEditBox.node.on('editing-did-ended', this.numberEditboxCallback, this);
        this.findEditBox.node.on('editing-did-ended', this.findEditboxCallback, this);

        var empty = []
        cc.sys.localStorage.setItem('names', JSON.stringify(empty));
        cc.sys.localStorage.setItem('numbers', JSON.stringify(empty));
        
        var emptyStr = ''
        cc.sys.localStorage.setItem('popup', JSON.stringify(emptyStr));
       

      
    },

    start: function () {
        this.timer = 0.0
    },

    update (dt) {
        this.timer += dt;

        if (this.timer >= 1.0) {
            this.timer = 0;

            this.scrollView.content.removeAllChildren();
            
            var names = JSON.parse(cc.sys.localStorage.getItem('names'));
            var numbers = JSON.parse(cc.sys.localStorage.getItem('numbers'));
            this.popUp.string = JSON.parse(cc.sys.localStorage.getItem('popup'));
           
            for (var i=0; i < names.length; i++) {
                var item = cc.instantiate(this.itemPrefab);
                this.scrollView.content.addChild(item);
                item.getComponent('ItemTemplate').init({
                    id: i,
                    itemName: names[i],
                    itemPrice: numbers[i]
                })
            }
        }
        
        
    },

    onAddButtonClick: function() {
        var _names = JSON.parse(cc.sys.localStorage.getItem('names'));
        var _numbers = JSON.parse(cc.sys.localStorage.getItem('numbers'));
        
        _names.push(JSON.parse(cc.sys.localStorage.getItem('editbox_name')));
        _numbers.push(JSON.parse(cc.sys.localStorage.getItem('editbox_number')));
        
        cc.sys.localStorage.setItem('names', JSON.stringify(_names));
        cc.sys.localStorage.setItem('numbers', JSON.stringify(_numbers));
    },

    onDelButtonClick: function() {

        var _names = JSON.parse(cc.sys.localStorage.getItem('names'));
        var _numbers = JSON.parse(cc.sys.localStorage.getItem('numbers'));
        var editName = JSON.parse(cc.sys.localStorage.getItem('editbox_name'));
        var editNum = JSON.parse(cc.sys.localStorage.getItem('editbox_number'));
        
        for (var i=0; i<_names.length; i++) {
            if(_names[i] == editName) {
                if(_numbers[i] == editNum) {
                    _names.splice(i, 1);
                    _numbers.splice(i, 1);
                    cc.sys.localStorage.setItem('names', JSON.stringify(_names));
                    cc.sys.localStorage.setItem('numbers', JSON.stringify(_numbers));
                    return;
                }
            }
        }
        cc.sys.localStorage.setItem('popup', JSON.stringify('없는 번호입니다.'));
    },

    onFindButtonClick: function() {

        var _names = JSON.parse(cc.sys.localStorage.getItem('names'));
        var _numbers = JSON.parse(cc.sys.localStorage.getItem('numbers'));
        var editName = JSON.parse(cc.sys.localStorage.getItem('editbox_find'));
        
        
        for (var i=0; i<_names.length; i++) {
            if(_names[i] == editName) {
                cc.sys.localStorage.setItem('popup', JSON.stringify(_names[i] + ' ' + _numbers[i]));
                return;
            }
        }
        cc.sys.localStorage.setItem('popup', JSON.stringify('없는 번호입니다.'));
    },

    nameEditboxCallback: function (editbox) {
        cc.sys.localStorage.setItem('editbox_name', JSON.stringify(editbox.string));
    },

    numberEditboxCallback: function (editbox) {
        cc.sys.localStorage.setItem('editbox_number', JSON.stringify(editbox.string));
    },

    findEditboxCallback: function (editbox) {
        cc.sys.localStorage.setItem('editbox_find', JSON.stringify(editbox.string));
    }
    
});
