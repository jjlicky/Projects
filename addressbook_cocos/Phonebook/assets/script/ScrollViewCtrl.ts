// Learn TypeScript:
//  - https://docs.cocos.com/creator/manual/en/scripting/typescript.html
// Learn Attribute:
//  - https://docs.cocos.com/creator/manual/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - https://docs.cocos.com/creator/manual/en/scripting/life-cycle-callbacks.html

const {ccclass, property} = cc._decorator;

@ccclass
export default class NewClass extends cc.Component {

    @property(cc.ScrollView)
    scrollView : cc.ScrollView = null;

    @property
    items : string [];

    @property
    content = null;
    
    
    @property(cc.Prefab)
    listItem: cc.Prefab = null;


    // LIFE-CYCLE CALLBACKS:

    onLoad() {
        this.content = this.scrollView.content;

        for (var i=0; i<20; i++) {
            this.addItem();
        }
    }

    addItem ():void {
        var item = cc.instantiate(this.listItem);
        this.content.addChild(item);
        this.items.push();
    }

    removeItem ():void {
        this.content.removeChild(this.items.pop());
    }



    //start () {

    //}

    // update (dt) {}
}
