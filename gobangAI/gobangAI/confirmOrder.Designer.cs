namespace gobangAI
{
    partial class confirmOrder
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.youFirst = new System.Windows.Forms.RadioButton();
            this.computerFirst = new System.Windows.Forms.RadioButton();
            this.OKButton = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.youFirst);
            this.groupBox1.Controls.Add(this.computerFirst);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(350, 129);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "请选择先手";
            // 
            // youFirst
            // 
            this.youFirst.AutoSize = true;
            this.youFirst.Location = new System.Drawing.Point(6, 77);
            this.youFirst.Name = "youFirst";
            this.youFirst.Size = new System.Drawing.Size(137, 28);
            this.youFirst.TabIndex = 1;
            this.youFirst.Text = "你为先手";
            this.youFirst.UseVisualStyleBackColor = true;
            // 
            // computerFirst
            // 
            this.computerFirst.AutoSize = true;
            this.computerFirst.Checked = true;
            this.computerFirst.Location = new System.Drawing.Point(6, 34);
            this.computerFirst.Name = "computerFirst";
            this.computerFirst.Size = new System.Drawing.Size(137, 28);
            this.computerFirst.TabIndex = 0;
            this.computerFirst.TabStop = true;
            this.computerFirst.Text = "电脑先手";
            this.computerFirst.UseVisualStyleBackColor = true;
            // 
            // OKButton
            // 
            this.OKButton.Location = new System.Drawing.Point(203, 147);
            this.OKButton.Name = "OKButton";
            this.OKButton.Size = new System.Drawing.Size(159, 70);
            this.OKButton.TabIndex = 2;
            this.OKButton.Text = "OK";
            this.OKButton.UseVisualStyleBackColor = true;
            this.OKButton.Click += new System.EventHandler(this.OKButton_Click);
            // 
            // confirmOrder
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 24F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(374, 229);
            this.Controls.Add(this.OKButton);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "confirmOrder";
            this.Text = "confirmOrder";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton youFirst;
        private System.Windows.Forms.RadioButton computerFirst;
        private System.Windows.Forms.Button OKButton;
    }
}