using UnityEngine;
[RequireComponent(typeof(Inimigo))]

public abstract class InimigoComportamento : MonoBehaviour
{
    public Inimigo inimigo { get; private set; }
    public float duracao;

    private void Awake()
    {
        this.inimigo = GetComponent<Inimigo>();
        this.enabled = false;
    }

    public void Enable()
    {
        Enable(this.duracao);
    }

    public virtual void Enable(float duracao)
    {   
        this.enabled = true;
        CancelInvoke();
        Invoke(nameof(Disable), duracao);
    }

    public virtual void Disable()
    {
        this.enabled = false;

        CancelInvoke();
    }
}
