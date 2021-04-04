cc.Class({
    extends: cc.Component,

    properties: {

        editBox : {
            default : null,
            type : cc.EditBox
        },

        _string: '',
        /**
         * !#en Input string of EditBox.
         * !#zh 输入框的初始输入内容，如果为空则会显示占位符的文本。
         * @property {String} string
         */
        string: {
           
            get () {
                return this._string;
            },
            set(value) {
                value = '' + value;
                if (this.maxLength >= 0 && value.length >= this.maxLength) {
                    value = value.slice(0, this.maxLength);
                }

                this._string = value;
                this._updateString(value);
            }
        }
    },

    onLoad : function() {
        this._string = this.editBox.Text_LABEL;
    }
});